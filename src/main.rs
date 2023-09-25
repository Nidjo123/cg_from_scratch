use cg_from_scratch::canvas::{Canvas, CanvasPosition};
use cg_from_scratch::color::Color;
use image::{Rgb, RgbImage};
use show_image::{event, ImageInfo, ImageView, WindowOptions};

struct Image {
    image: RgbImage,
}

impl Image {
    pub fn new(width: u32, height: u32) -> Self {
        let image = RgbImage::new(width, height);
        Image { image }
    }

    pub fn image_view(&self) -> ImageView {
        ImageView::new(
            ImageInfo::rgb8(self.image.width(), self.image.height()),
            self.image.as_raw(),
        )
    }
}

impl Canvas for Image {
    fn width(&self) -> u32 {
        self.image.width()
    }

    fn height(&self) -> u32 {
        self.image.height()
    }

    fn put_pixel(&mut self, position: &CanvasPosition, color: &Color) {
        let width = self.width() as i32;
        let height = self.height() as i32;
        let screen_x = ((position.x + width / 2) as u32).clamp(0, self.width() - 1);
        let screen_y = ((position.y + height / 2) as u32).clamp(0, self.height() - 1);
        self.image
            .put_pixel(screen_x, screen_y, Rgb(color.as_rgb_array()));
    }
}

fn put_line(canvas: &mut dyn Canvas, y: i32) {
    let width = canvas.width() as i32;
    for x in -width / 2..width {
        canvas.put_pixel(&CanvasPosition { x, y }, &Color::from_rgb(255, 255, 255));
    }
}

#[show_image::main]
fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut image = Image::new(256, 256);
    put_line(&mut image, 0);
    let window = show_image::create_window("Image", WindowOptions::default())?;

    let image_view = image.image_view();
    window.set_image("main", image_view)?;

    for event in window.event_channel()? {
        if let event::WindowEvent::KeyboardInput(event) = event {
            println!("{:#?}", event);
            if event.input.key_code == Some(event::VirtualKeyCode::Escape)
                && event.input.state.is_pressed()
            {
                break;
            }
        }
    }

    Ok(())
}
