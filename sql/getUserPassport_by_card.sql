use atm;

SELECT user_passport_num
FROM card
WHERE card_num = :card_num;