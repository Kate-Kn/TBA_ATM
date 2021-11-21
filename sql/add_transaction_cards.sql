use atm;

INSERT INTO transaction_cards (id, transaction_sum, transaction_date, transaction_description, 
card1_card_num, card1_currency_name, card1_user_passport_num, 
card2_card_num, card2_currency_name, card2_user_passport_num)
VALUES (:id, :transaction_sum, :transaction_date, :transaction_description,
:card1_card_num, :card1_currency_name, :card1_user_passport_num,
:card2_card_num, :card2_currency_name, :card2_user_passport_num);