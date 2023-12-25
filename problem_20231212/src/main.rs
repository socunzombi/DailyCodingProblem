
mod xor_linked_list;

fn main() {
    let mut xor_list = xor_linked_list::XORLinkedList::new();
    xor_list.add(1);
    xor_list.add(2);
    xor_list.add(3);

    xor_list.print();
}