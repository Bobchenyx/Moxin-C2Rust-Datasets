words.iter_mut()
    .for_each(|word| {
    // use `unsafe` to fasten the reversing operation.
    // the words contain only English letters which are encoded in ASCII
    unsafe {
        word.as_bytes_mut().reverse();
    }
});