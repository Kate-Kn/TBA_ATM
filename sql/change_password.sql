use atm;

UPDATE card
SET pincode = :pincode
WHERE card_num = :card_num;