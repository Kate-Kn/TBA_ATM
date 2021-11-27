use atm;

SELECT company_id
FROM bank_account
WHERE iban= :iban;