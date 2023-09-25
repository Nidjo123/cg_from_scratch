use crate::color::Color;

pub struct CanvasPosition {
    pub x: i32,
    pub y: i32,
}

pub trait Canvas {
    fn width(&self) -> u32;
    fn height(&self) -> u32;
    fn put_pixel(&mut self, position: &CanvasPosition, color: &Color);
}
