use image::{Rgb, RgbImage};
use show_image::{event, ImageInfo, ImageView, WindowOptions};
use canvas::{Canvas, Color, CanvasPosition};

mod canvas;


impl Canvas for RgbImage {
    fn width(&self) -> u32 {
        self.width()
    }

    fn height(&self) -> u32 {
        self.height()
    }

    fn put_pixel(&mut self, position: &CanvasPosition, color: &Color) {
        self.put_pixel(position.x, position.y, Rgb(color.as_rgb_array()));
    }
}

fn put_line(canvas: &mut dyn Canvas, y: u32) {
    for x in 0..canvas.width() {
        canvas.put_pixel(&CanvasPosition { x, y }, &Color::from_rgb(255, 255, 255));
    }
}

#[show_image::main]
fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut image = RgbImage::new(256, 256);
    put_line(&mut image, 50);
    let window = show_image::create_window("Image", WindowOptions::default())?;

    let image = ImageView::new(ImageInfo::rgb8(image.width(), image.height()), image.as_raw());
    window.set_image("main", image)?;

    for event in window.event_channel()? {
        if let event::WindowEvent::KeyboardInput(event) = event {
            println!("{:#?}", event);
            if event.input.key_code == Some(event::VirtualKeyCode::Escape) && event.input.state.is_pressed() {
                break;
            }
        }
    }

    Ok(())
}
