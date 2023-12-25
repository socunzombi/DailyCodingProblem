use std::ptr;

pub struct Node<u32> 
{
    data:u32,
    xor_ptr: *mut Node<u32>,
}

impl <u32> Node <u32> 
{
    fn new (data:u32) -> Self 
    {
        Node 
        { 
            data, 
            xor_ptr: ptr::null_mut() 
        }
    }
}

pub struct XORLinkedList<u32> 
{
    head: *mut Node<u32>,
    tail: *mut Node<u32>,
}

impl<u32: std::fmt::Display> XORLinkedList<u32> 
{
    pub fn new() -> Self 
    {
        XORLinkedList 
        {
            head: ptr::null_mut(),
            tail: ptr::null_mut(),
        }
    }

    pub fn add(&mut self, data:u32) 
    {
        let new_node = Box::into_raw(Box::new(Node::new(data)));

        if self.head.is_null() 
        {
            self.head = new_node;
            self.tail = new_node;
        } 
        else 
        {
            let prev_xor_ptr = ptr::null_mut();
            let current_xor_ptr = self.head;

            let new_xor_ptr = XORLinkedList::xor_ptrs(prev_xor_ptr, current_xor_ptr);

            unsafe 
            {
                (*new_node).xor_ptr = new_xor_ptr;
                (*self.head).xor_ptr = XORLinkedList::xor_ptrs(new_node, ptr::null_mut());
                self.head = new_node;
            }
        }
    }

    fn xor_ptrs(a:*mut Node<u32>, b:*mut Node<u32>) -> *mut Node<u32> 
    {
        (a as usize ^ b as usize) as *mut Node<u32>
    }

    pub fn print(&self) 
    {
        let mut current = self.head;
        let mut prev = ptr::null_mut();

        while !current.is_null() 
        {
            unsafe 
            {
                print!("{} ", (*current).data);
                let next = XORLinkedList::xor_ptrs(prev, (*current).xor_ptr);
                prev = current;
                current = next;
            }
        }
        println!();
    }
}