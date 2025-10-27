impl Solution {
    pub fn convert_integer(a: i32, b: i32) -> i32 {
        #[cfg(target_arch = "x86")]
        use core::arch::x86::_popcnt32;

        #[cfg(target_arch = "x86_64")]
        use core::arch::x86_64::_popcnt32;

        unsafe { _popcnt32(a ^ b) }
    }
}