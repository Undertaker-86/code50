-- Keep a log of any SQL queries you execute as you solve the mystery.

--crime description
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street - 'Humphrey Street';

--bakery description
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 16;
--information get: license plate : 4468KVT

--interview
SELECT * FROM interviews WHERE month = 7 AND day = 28;
-- --information get:
-- Ruth: car in the "bakery"
-- Eugene: someone she knows and found at "ATM" at Leggett Street
-- Raymond: Called for "less than a minute", "earliest flight out of FIFtyville tomorrow", "asked the phone user for ticket"

--atm transaction
SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = "Leggett Street";
--found a list of people withdrawing money

--people

SELECT * FROM people WHERE license_plate ='4468KVT'; --this is wrong!!!!!!
-- |   id   | name |  phone_number  | passport_number | license_plate |
-- +--------+------+----------------+-----------------+---------------+
-- | 677698 | John | (016) 555-9166 | 8174538026      | 4468KVT       |
-- +--------+------+----------------+-----------------+----------

--phone calls
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration <= 60;


--trying to narrow down atm
SELECT distinct(name) FROM
atm_transactions JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON airports.id = flights.origin_airport_id
WHERE bakery_security_logs.day = 28 AND bakery_security_logs.month = 7
AND atm_location = "Leggett Street" AND duration <= 60 AND flights.day = 29 AND flights.month = 7 AND bakery_security_logs.activity = 'exit' AND atm_transactions.transaction_type = 'withdraw' AND flights.id = 36 AND bakery_security_logs.minute <= 25;

SELECT * FROM
--narrow down with addition of phone calls