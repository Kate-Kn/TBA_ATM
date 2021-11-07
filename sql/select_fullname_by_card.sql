use atm;

SELECT first_name, surname
FROM atm_user INNER JOIN card on passport_num = user_passport_num
WHERE card_num = :card_num;