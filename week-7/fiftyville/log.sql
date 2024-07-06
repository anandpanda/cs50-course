-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Checking the description of the crime happened at the given location and time.
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND street = 'Humphrey Street';

-- Found two incidents that day: one related to theft and the other to littering.

-- Finding the names of the witnesses from the interviews table and checking their transcripts.
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28;

-- Found two transcripts with the name "Eugene". Checking how many Eugenes are present in the 'people' table.
SELECT name
  FROM people
 WHERE name = 'Eugene';

-- Found out that there is only one Eugene. Proceeding accordingly.

-- Finding the names of the three witnesses from the list of names of people who gave interviews on July 28, 2021.
-- Crime report said that the witnesses mentioned "bakery" in their transcripts. Ordering the results alphabetically by the names of witnesses.
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND transcript LIKE '%bakery%'
 ORDER BY name;

-- Witnesses are: Eugene, Raymond, and Ruth.

-- Eugene's clue: Thief was withdrawing money from the ATM on Leggett Street. Checking the account number of the person who did that transaction.
SELECT account_number, amount
  FROM atm_transactions
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

-- Finding the names associated with the corresponding account numbers. Adding these names to the 'Suspect List'.
SELECT people.name, atm_transactions.amount
  FROM people
  JOIN bank_accounts ON people.id = bank_accounts.person_id
  JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
 WHERE atm_transactions.year = 2021
   AND atm_transactions.month = 7
   AND atm_transactions.day = 28
   AND atm_transactions.atm_location = 'Leggett Street'
   AND atm_transactions.transaction_type = 'withdraw';

-- Raymond's clue: The thief called a person and talked for less than a minute, asking them to buy a flight ticket for the earliest flight on July 29, 2021.
-- Finding the airport in Fiftyville which would be the origin of the flight.
SELECT abbreviation, full_name, city
  FROM airports
 WHERE city = 'Fiftyville';

-- Finding the flights on July 29 from Fiftyville airport, ordered by time.
SELECT flights.id, full_name, city, flights.hour, flights.minute
  FROM airports
  JOIN flights ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville')
   AND flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
 ORDER BY flights.hour, flights.minute;

-- First flight is at 8:20 AM to LaGuardia Airport in New York City (Flight id- 36). Checking the list of passengers on that flight and adding them to the 'Suspect List'.
SELECT people.name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN flights ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 8
   AND flights.minute = 20
 ORDER BY passengers.passport_number;

-- Checking the phone call records to find the person who bought the tickets.
-- Possible callers (duration <= 60 seconds). Adding these names to the 'Suspect List'.
SELECT people.name, phone_calls.duration
  FROM people
  JOIN phone_calls ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- Possible call-receivers (duration <= 60 seconds).
SELECT people.name, phone_calls.duration
  FROM people
  JOIN phone_calls ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- Ruth's clue: The thief drove away in a car from the bakery within 10 minutes from the theft.
-- Checking the license plates of cars within that time frame. Then, checking the names of those cars' owners.
SELECT people.name, bakery_security_logs.hour, bakery_security_logs.minute
  FROM people
  JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021
   AND bakery_security_logs.month = 7
   AND bakery_security_logs.day = 28
   AND bakery_security_logs.activity = 'exit'
   AND bakery_security_logs.hour = 10
   AND bakery_security_logs.minute BETWEEN 15 AND 25
 ORDER BY bakery_security_logs.minute;

-- Concluding that Bruce is the thief as he is present in all the four lists: list of passengers, list of people who did the specific ATM transactions, list of people who called, and list of people who drove away in cars from the bakery.
-- Bruce must have escaped to New York City, as he took the New York City flight.
-- Robin must be the accomplice who purchased the flight ticket and helped Bruce escape to New York City.
