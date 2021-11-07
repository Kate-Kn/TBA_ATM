use atm;

INSERT INTO transaction_cash(id, transaction_sum, transaction_date, transaction_description, card_card_num, 
card_currency_name, card_user_passport_num)
VALUES (:id, :transaction_sum, :transaction_date, :transaction_description, :card_card_num,
:card_currency_name, :card_user_passport_num);