fn fib_2(n: i32) -> i32 {
    let mut a = 0;
    let mut b = 1;
    let mut c = 0;
    if n == 0 || n == 1 {
        n
    } else {
        for number in 2..(n + 1) {
            c = a + b;
            a = b;
            b = c;
        }
        c
    }
}


//递归的本地可以，这里报错，可能是语言不熟悉的问题
fn fib(n: i32) -> i32 {
    if n == 0 {
        0
    } else if n == 1 {
        1
    } else {
        fib(n - 1) + fib(n - 2)
    }
}