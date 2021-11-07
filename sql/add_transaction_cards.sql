use atm;

INSERT INTO transaction_cards (id, transaction_sum, transaction_date, transaction_description, 
card_card_from, card1_currency_from, card1_user_passport_from, 
card_card_to, card_currency_to, card_user_passport_to)
VALUES (:id, :transaction_sum, :transaction_date, :transaction_description,
:card_card_from, :card1_currency_from, :card1_user_passport_from,
:card_card_to, :card_currency_to, :card_user_passport_to);