struct MinStack {
    stack: Vec<i32>,
    min_stack: Vec<i32>,
}

impl MinStack {
    /** initialize your data structure here. */
    fn new() -> Self {
        Self{
            stack: Vec::new(),
            min_stack: Vec::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        if self.stack.is_empty() || x <= self.get_min()  {
            self.stack.push(x);
            self.min_stack.push(x);
        } else {
            self.stack.push(x);
        }
    }
    
    fn pop(&mut self) {
        if let Some(v) = self.stack.pop(){
            if v == self.get_min() {
                self.min_stack.pop();
            }
        }
    }
    
    fn top(&self) -> i32 {
        if let Some (v) = self.stack.last() {
            *v
        } else {
            std::i32::MAX
        }
    }
    
    fn get_min(&self) -> i32 {
        if let Some (v) = self.min_stack.last() {
            *v
        } else {
            std::i32::MAX
        }
    }
}