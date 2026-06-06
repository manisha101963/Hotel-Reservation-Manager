# Hotel-Reservation-Manager
OOP II Final Exam Project - Hotel Reservation CLI System in C++



# MPS Hotel Reservation Manager

## Project Overview

MPS Hotel Reservation Manager is a console-based hotel reservation system developed in C++ using Object-Oriented Programming (OOP) concepts. The system allows customers to view room types, make reservations, process payments, and manage bookings. Reservation data is stored using text files to ensure persistence even after the program is closed.

The project simulates a real hotel booking system and demonstrates the practical application of OOP principles such as encapsulation, inheritance, polymorphism, abstraction, composition, file handling, and input validation.

---

## Features

### Room Management

* Single Room
* Double Room
* Deluxe Room
* Display room features
* Check room availability
* Mark rooms as booked

### Guest Management

* Store Guest ID
* Store Guest Name
* Store Phone Number
* Input validation for guest information

### Reservation Management

* Automatic Reservation ID generation
* Check-in and Check-out dates
* Calculate total price based on nights stayed
* View all reservations
* Cancel reservations

### Payment Management

* Credit Card payment
* Debit Card payment
* Card holder validation
* Card number validation
* Masked card number display for security

### File Handling

* Save reservations permanently
* Save guest information
* Save payment information
* Load booked rooms automatically when program starts

### Input Validation

* Invalid room type prevention
* Invalid room number prevention
* Guest ID numeric validation
* Name validation
* Phone number validation
* Date format validation
* Card holder validation
* Card number validation

---

## OOP Concepts Used

### Encapsulation

Data members are kept private and accessed through public methods.

### Inheritance

The following classes inherit from the Room class:

* SingleRoom
* DoubleRoom
* DeluxeRoom

### Polymorphism

Room pointers and virtual functions are used to allow different room types to behave differently through a common interface.

### Abstraction

Complex internal operations are hidden behind simple methods such as:

* bookRoom()
* cancelBooking()
* processPayment()

### Composition

* Reservation contains a Payment object.
* HotelManager manages Rooms and Reservations.

---

## Project Structure

```text
Hotel-Reservation-Manager
│
├── include/
│   ├── Room.h
│   ├── SingleRoom.h
│   ├── DoubleRoom.h
│   ├── DeluxeRoom.h
│   ├── Guest.h
│   ├── Reservation.h
│   ├── Payment.h
│   └── HotelManager.h
│
├── src/
│   ├── main.cpp
│   ├── Room.cpp
│   ├── SingleRoom.cpp
│   ├── DoubleRoom.cpp
│   ├── DeluxeRoom.cpp
│   ├── Guest.cpp
│   ├── Reservation.cpp
│   ├── Payment.cpp
│   └── HotelManager.cpp
│
├── data/
│   ├── reservations.txt
│   ├── guests.txt
│   ├── payments.txt
│   └── users.txt
│
├── Makefile
└── README.md
```

---

## How to Compile and Run

### Method 1: Using g++

Compile:

```bash
g++ src/*.cpp -Iinclude -o hotel
```

Run:

```bash
.\hotel.exe
```

### Method 2: Using Makefile

Build:

```bash
mingw32-make
```

Run:

```bash
.\hotel.exe
```

---

## Data Files

### reservations.txt

Stores reservation information:

```text
ReservationID | GuestID | GuestName | Phone | RoomNumber | RoomType | CheckInDate | CheckOutDate | Nights | TotalPrice
```

### guests.txt

Stores guest information:

```text
GuestID | GuestName | Phone
```

### payments.txt

Stores payment information:

```text
ReservationID | PaymentMethod | MaskedCardNumber
```

### users.txt

Reserved for future login and registration system.

---

## Limitations

* The system manages only one hotel (MPS Hotel).
* It does not search hotels in different locations.
* One reservation can book only one room.
* Customers cannot upgrade or downgrade room type after booking.
* Customers must cancel and create a new reservation to change rooms.
* The system uses text files instead of a database.
* Login and registration features are not yet implemented.
* Fixed-size arrays are used for room management.

---

## Future Improvements

* User Login and Registration System
* Multiple Hotel Support
* Hotel Search by Location
* Room Upgrade and Downgrade Feature
* Database Integration (MySQL)
* Graphical User Interface (GUI)
* Online Payment Gateway Integration
* Multiple Room Booking in a Single Reservation
* Admin Dashboard

---

## Conclusion

The MPS Hotel Reservation Manager successfully demonstrates the use of Object-Oriented Programming concepts in a real-world hotel booking scenario. The project provides room management, reservation handling, payment processing, file storage, and input validation while maintaining a modular and organized structure.

how we can run the code form make file 
in terminal type:
mingw32-make
then enter then
.\hotel.exe
then enter
