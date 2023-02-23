-- Hay que mantener un registro de cualquier consulta SQL que ejecute mientras resuelve el misterio.

-- Comprobación de la descripción del delito ocurrido en el lugar y la hora determinados.
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND street = 'Humphrey Street';

-- Dos incidentes ocurrieron ese día. Solo uno está relacionado con el robo. Otro está relacionado con tirar basura.

-- Los testigos podrían ser los cómplices. Entonces, encontrar los nombres de los testigos de la mesa de entrevistas. Además, revisando las transcripciones de sus entrevistas.
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28;

-- Encontré dos transcripciones con el nombre: Eugene, así que comprobé cuántos Eugenes están presentes en la tabla de 'personas'.
SELECT name
  FROM people
 WHERE name = 'Eugene';

-- Descubrí que solo hay un Eugene. Entonces, procediendo en consecuencia.

/*
    Encontrar los nombres de los 3 testigos de la lista de nombres de personas que dieron entrevistas el 28 de julio de 2021.
    El informe del crimen dijo que los testigos mencionaron "panadería" en sus transcripciones. Además, ordenar alfabéticamente los resultados por los nombres de los testigos.SELECT name, transcript
*/
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND transcript LIKE '%bakery%'
 ORDER BY name;

-- Los testigos son: Eugene, Raymond y Ruth.

-- Eugene dio pistas: Thief estaba retirando dinero del cajero automático en Leggett Street. Entonces, verificando el número de cuenta de la persona que hizo esa transacción.

SELECT account_number, amount
  FROM atm_transactions
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

-- Encontrar los nombres asociados con los números de cuenta correspondientes. Poner estos nombres en la 'Lista de sospechosos'

SELECT name, atm_transactions.amount
  FROM people
  JOIN bank_accounts
    ON people.id = bank_accounts.person_id
  JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
 WHERE atm_transactions.year = 2021
   AND atm_transactions.month = 7
   AND atm_transactions.day = 28
   AND atm_transactions.atm_location = 'Leggett Street'
   AND atm_transactions.transaction_type = 'withdraw';


/*
    Raymond dio pistas-- Al salir de la panadería, llamaron a una persona y hablaron por menos de un minuto. Le pidieron a la persona al otro lado de la llamada que comprara un boleto de avión
    del primer vuelo del 29 de julio de 2021.-- Primero encontrando la información sobre el aeropuerto de Fiftyville que sería el origen de la huida del ladrón.
*/

SELECT abbreviation, full_name, city
  FROM airports
 WHERE city = 'Fiftyville';

-- Encontrar los vuelos del 29 de julio desde el aeropuerto de Fiftyville y ordenarlos por tiempo.

SELECT flights.id, full_name, city, flights.hour, flights.minute
  FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
   AND flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
 ORDER BY flights.hour, flights.minute;

-- El primer vuelo sale a las 8:20 al aeropuerto LaGuardia en la ciudad de Nueva York (Vuelo id-36). Este podría ser el lugar al que fue el ladrón.
-- Comprobando la lista de pasajeros en ese vuelo. Poniéndolos a todos en 'Lista de sospechosos'. Ordenar los nombres según sus números de pasaporte.

SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 8
   AND flights.minute = 20
 ORDER BY passengers.passport_number;

-- Revisando los registros de llamadas telefónicas para encontrar a la persona que compró los boletos.
-- En primer lugar, comprobar los posibles nombres de la persona que llama y poner estos nombres en la 'Lista de sospechosos'. Ordenándolas según la duración de las llamadas.

SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- En segundo lugar, comprobar los posibles nombres del receptor de la llamada. Ordenándolas según la duración de las llamadas.

SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;

/*
    Ruth dio pistas- El ladrón se alejó en un auto de la panadería, a los 10 minutos del robo.
    SO, verificar las matrículas de los automóviles dentro de ese período de tiempo. Luego, revisando los nombres de los dueños de esos autos. Podrían ser sospechosos.
*/
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
  FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021
   AND bakery_security_logs.month = 7
   AND bakery_security_logs.day = 28
   AND bakery_security_logs.activity = 'exit'
   AND bakery_security_logs.hour = 10
   AND bakery_security_logs.minute >= 15
   AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;

/*
    Bruce debe ser el ladrón ya que está presente en las 4 listas: Lista de pasajeros,
    lista de personas que realizaron transacciones específicas en cajeros automáticos, lista de personas que llamaron y lista de personas que se alejaron en autos de la panadería.

    Debe haber escapado a la ciudad de Nueva York, ya que tomó el vuelo de la ciudad de Nueva York.
    Robin debe ser el cómplice que compró el boleto de avión y ayudó a Bruce a escapar a la ciudad de Nueva York.
*/