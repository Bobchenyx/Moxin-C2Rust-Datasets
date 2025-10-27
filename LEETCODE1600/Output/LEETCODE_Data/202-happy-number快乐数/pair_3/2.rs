impl Solution 
{
    pub fn is_happy(n: i32) -> bool 
    {
        let vec = vec![4,16,37,58,89,145,42,20];
        let mut z = n;
        loop
        {
        let mut flag = 0;
        for i in 0..7
        {
            if z==vec[i]
            {
                return false;
            }
        }
        loop
        {
            flag += (z%10)*(z%10);
            z /= 10;
            if z <= 0
            {
                break;
            }
        }
        if flag == 1
        {
            return true;
        }
        z = flag;
        }
    }
}