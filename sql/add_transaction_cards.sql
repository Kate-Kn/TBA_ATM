use atm;

INSERT INTO transaction_cards (transaction_sum, transaction_date, transaction_description, 
card_card_from, card_currency_from, card_user_passport_from, 
card_card_to, card_currency_to, card_user_passport_to)
VALUES (:transaction_sum, :transaction_date, :transaction_description,
:card_card_from, :card_currency_from, :card_user_passport_from,
:card_card_to, :card_currency_to, :card_user_passport_to);