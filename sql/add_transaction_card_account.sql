use atm;

INSERT INTO transaction_card_account (transaction_sum, transaction_date, transaction_description, card_card_num,
card_currency_name, card_user_passport_num, account_iban, account_company_id,
account_account_type_code, account_currency_name)
VALUES (:transaction_sum, :transaction_date, :transaction_description, :card_card_num,
:card_currency_name, :card_user_passport_num, :account_iban, :account_company_id,
:account_account_type_code, :account_currency_name);