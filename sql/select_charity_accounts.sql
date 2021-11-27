use atm;

SELECT company.title, bank_account.iban
FROM company INNER JOIN  bank_account ON company.id = bank_account.company_id
WHERE account_type_code IN (
   SELECT account_type_code
   FROM account_type
   WHERE type_description  LIKE '%charity%');