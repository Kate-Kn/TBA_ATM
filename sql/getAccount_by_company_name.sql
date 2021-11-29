use atm;

SELECT iban, acc_name, company_id, account_type_code, currency_name
FROM bank_account
WHERE company_id IN (
  SELECT id
  FROM company
  WHERE title LIKE :title
); 