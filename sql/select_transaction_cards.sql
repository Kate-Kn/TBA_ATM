use atm;

SELECT*
FROM transaction_cards
WHERE card_card_from= :card_card_from
AND card_card_to= :card_card_to;