pub struct CanvasPosition {
    pub x: u32,
    pub y: u32,
}

pub struct Color {
    r: u8,
    g: u8,
    b: u8,
}

impl Color {
    pub fn from_rgb(r: u8, g: u8, b: u8) -> Self {
        Self { r, g, b }
    }

    pub fn as_rgb_array(&self) -> [u8; 3] {
        [self.r, self.g, self.b]
    }
}

pub trait Canvas {
    fn width(&self) -> u32;
    fn height(&self) -> u32;
    fn put_pixel(&mut self, position: &CanvasPosition, color: &Color);
}
