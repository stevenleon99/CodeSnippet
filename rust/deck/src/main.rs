struct Deck {
    cards: Vec<String>,
}


fn main() {
    let deck: Deck = Deck {
        cards: vec![]
    };
    
    println!("Deck created with {} cards", deck.cards.len());
}
