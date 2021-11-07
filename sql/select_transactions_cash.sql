use atm;

SELECT *
FROM transaction_cash
WHERE card_card_num= :card_card_num;