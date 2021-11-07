use atm;

SELECT *
FROM bank_account
WHERE account_type_code IN (
   SELECT account_type_code
   FROM account_type
   WHERE type_description  LIKE '%charity%');