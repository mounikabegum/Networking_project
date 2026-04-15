# Networking_project
# 🚗 HARP – Hybrid Adaptive Routing Protocol (VANET)

## 📌 Project Overview

This project implements a simplified version of the **Hybrid Adaptive Routing Protocol (HARP)** for Vehicular Ad Hoc Networks (VANETs).

HARP improves communication between vehicles by selecting routes based on **link stability** instead of only shortest distance.

---

## ❗ Problem Statement

Vehicular networks are highly dynamic because vehicles move at high speeds. This leads to:

* Frequent link breakages
* High packet loss
* Increased delay

Traditional routing protocols like **AODV** are not efficient in such environments.

---

## 💡 Proposed Solution

The **HARP protocol** combines features of reactive and proactive routing.

It selects routes based on:

* Distance between vehicles
* Speed difference
* Link stability

This ensures more reliable communication in VANETs.

---

## ⚙️ Features

* Simulation of vehicle nodes
* Distance calculation using coordinates
* Link stability estimation
* Adaptive route selection
* Routing table generation

---

## 🛠️ Tech Stack

* Language: C
* Concepts: Computer Networks, VANET, Routing Protocols

---

## 🧠 Working

1. Vehicles are added with position and speed

2. Distance between vehicles is calculated

3. Link stability is computed using:

   stability = 1 / (1 + speed difference + distance)

4. The route with highest stability is selected

5. Routing table is displayed

---

## ▶️ How to Run

### Compile

```bash
gcc harp.c -o harp -lm
```

### Run

```bash
./harp
```

---

## 📊 Sample Output

```
Route Found via Node 1
Link Stability: 0.018

Routing Table
Source: 0 -> Destination: 3 | Distance: 7.07 | Stability: 0.018
```

---

## 📈 Future Improvements

* Multi-hop routing support
* Integration with NS-3 simulator
* Real-time traffic simulation using SUMO
* Performance comparison with AODV and DSDV

---

## 🙋‍♀️ Author

Chimakurthy Mounika Begum
B.Tech – Computer Science
Amrita Vishwa Vidyapeetham

---
