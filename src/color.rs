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
