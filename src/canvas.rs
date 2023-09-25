use crate::color::Color;

pub struct CanvasPosition {
    pub x: i32,
    pub y: i32,
}

pub enum ImagePosition {
    Canvas { x: i32, y: i32 },
    Screen { x: u32, y: u32 },
}

pub trait Drawable {
    fn width(&self) -> u32;
    fn height(&self) -> u32;
    fn put_pixel(&mut self, position: ImagePosition, color: Color);
}
