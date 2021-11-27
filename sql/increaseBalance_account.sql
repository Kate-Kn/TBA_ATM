use atm;

UPDATE bank_account 
SET balance = balance + :balance 
WHERE iban=:iban;