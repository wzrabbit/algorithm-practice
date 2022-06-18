use std::io::{stdin, Read};
use std::fmt::Write;

fn main() {
    let mut fulltext = String::new();
    let mut output = String::new();
    stdin().read_to_string(&mut fulltext).unwrap();
    let n: u32 = fulltext.trim().parse().unwrap();
    
    
    for i in 1..=n {
        writeln!(output, "{}", "*".repeat(i as usize)).unwrap();
    }
    
    for i in (1..n).rev() {
        writeln!(output, "{}", "*".repeat(i as usize)).unwrap();
    }

    print!("{}", output);
}