# Engineering Notebooks

Python, C++, and Arduino work spanning signal processing, controls theory, thermal systems analysis, numerical methods, and embedded systems. Written by Pete Mathew — Automation & Controls Engineer at Yanfeng Automotive Interiors.

---

## Thermal Systems Analysis

### [`heating_pad_thermal_analysis.ipynb`](thermal-analysis/heating_pad_thermal_analysis.ipynb)
Real sensor data pipeline for a 4-probe heating pad system sampled at 1 Hz. Handles multi-format data ingestion (CSV + ODS), datetime parsing, and multi-file aggregation. Uses finite-difference derivative (dT/dt) to detect steady-state transition automatically. Generates publication-quality figures at 300 DPI with annotated peak temperatures and transition points.

**Stack:** `pandas` · `numpy` · `matplotlib` · `scipy`

---

## Signals & Systems

### [`laplace_fourier_frequency_analysis.ipynb`](signals-systems/laplace_fourier_frequency_analysis.ipynb)
Symbolic computation of Laplace and inverse Laplace transforms for piecewise and exponential signals, including repeated-pole cases. Derives Fourier series coefficients (a₀, aₙ, bₙ) analytically via integration, reconstructs periodic signals from finite harmonic approximations, and plots magnitude/phase frequency response |X(ω)| and ∠X(ω).

**Stack:** `sympy` · `numpy` · `matplotlib`

### [`fft_spectral_analysis.ipynb`](signals-systems/fft_spectral_analysis.ipynb)
FFT-based spectral analysis of multi-tone signals. Demonstrates the effect of zero-padding on frequency resolution, zero-stuffing, sign-flipping for spectral modulation, and aliasing from an undersampled signal. Compares padded vs. unpadded spectra and explains the Nyquist criterion.

**Stack:** `numpy` (rfft, rfftfreq) · `matplotlib`

### [`filter_design_convolution.ipynb`](signals-systems/filter_design_convolution.ipynb)
Digital filter design from pole-zero specifications. Loads pole/zero pairs, converts to transfer function coefficients via `zpk2tf`, computes impulse response, and plots pole-zero diagrams on the complex plane. Evaluates DTFT frequency response (amplitude in dB, phase in radians) and applies FIR filter constraints for passband/stopband design.

**Stack:** `scipy.signal` · `numpy` · `matplotlib`

### [`signal_filtering_fft.ipynb`](signals-systems/signal_filtering_fft.ipynb)
Generates composite sinusoid signals, computes double- and single-sided magnitude spectra, converts to dB scale manually (20·log₁₀), and compares against `matplotlib`'s built-in spectrum analyzer. Explores FFT padding effects on frequency resolution and energy distribution.

**Stack:** `scipy.fftpack` · `numpy` · `matplotlib`

---

## Numerical Methods

### [`dft_gaussian_elimination_newton_raphson.ipynb`](numerical-methods/dft_gaussian_elimination_newton_raphson.ipynb)
Three independent numerical implementations:
- **DFT/IDFT from scratch** — O(N²) discrete Fourier transform and its inverse; reconstructs a sampled cosine and verifies round-trip accuracy
- **Gaussian elimination** — manual forward elimination and back-substitution solver for a 3×3 linear system (no `numpy.linalg`)
- **Newton-Raphson root finding** — iterative solver for `cos(x) - x`, `x·tan(x) - 1`, and cubic polynomials; saves results to file

Also includes performance benchmarking (manual matrix multiply vs. `numpy.dot`) across matrix sizes 4×4–20×20 using `timeit`.

**Stack:** `numpy` · `matplotlib` · `timeit` · `math`

### [`taylor_series_signal_reconstruction.ipynb`](numerical-methods/taylor_series_signal_reconstruction.ipynb)
Implements `eˣ`, `e⁻ˣ`, `sin(x)`, and `cos(x)` from first principles using Taylor series summation with convergence to `error < 10⁻⁶`. Validates against the `math` library over 20 random test values and quantifies error per function. Also implements signal downsampling (x[2n], x[4n]) with linear interpolation recovery and Newton-Raphson for a quadratic root.

**Stack:** `numpy` · `math` · `random`

---

## Embedded Systems (C++ / Arduino)

### [`hex_counter_74HC595.ino`](embedded/hex_counter_74HC595.ino)
Drives a 7-segment display through a 74HC595 shift register via `shiftOut`. Reads hex characters (0–F) over Serial and maps them to segment bit patterns using a compile-time lookup table. Full wiring documentation included.

### [`payroll_calculator.cpp`](embedded/payroll_calculator.cpp)
Weekly payroll calculator for N employees. Validates hours worked (1–40), computes individual pay, accumulates total, and reports company average. Clean separation of validation, calculation, and I/O.

### [`grade_drop_calculator.cpp`](embedded/grade_drop_calculator.cpp)
Reads 5 grades, locates the lowest using a linear scan, drops it, and reports raw vs. adjusted averages. Demonstrates array passing by pointer, function decomposition, and formatted output.

### [`dice_gambling_game.cpp`](embedded/dice_gambling_game.cpp)
Console dice game with betting logic, randomized rolls, input validation, and balance tracking across rounds.

---

*Automation & Controls Engineer · Yanfeng Automotive Interiors · EE @ TXST*
