use atm;

UPDATE card 
SET balance = balance + :balance 
WHERE card_num=:card_num;