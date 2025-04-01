# PdfManagement

**PdfManagement** è un'applicazione C++ per la gestione e la modifica di documenti PDF, sviluppata con il framework Qt e basata sulla libreria [PoDoFo](https://github.com/podofo/podofo).  
Permette di visualizzare, modificare e manipolare file PDF in modo semplice e intuitivo attraverso una GUI.

## 📁 Struttura del progetto

- `src/` — Codice sorgente dell'applicazione.
- `lib/podofo/` — Libreria PoDoFo integrata nel progetto.
- `test/` — Script e progetti di test.
- `Image/` — Risorse grafiche usate nella GUI.
- `mainwindow.ui` — Interfaccia grafica principale (Qt Designer).
- `Risorse.qrc` — File Qt Resource Collection per immagini e icone.
- `.idea/` — Configurazioni dell'IDE (es. CLion o Qt Creator).
- `CMakeLists.txt` — Script per la compilazione con CMake.

## ⚙️ Requisiti

- CMake ≥ 3.16
- Qt ≥ 5.12
- Compilatore C++11 o superiore
- (Opzionale) Qt Creator o CLion per lo sviluppo

## 🚀 Compilazione

1. Clona il repository:
   ```bash
   git clone https://github.com/MugnaiLorenzo/PdfManagement.git
   cd PdfManagement
