# LBYARCH_Agero,Sales_x86-to-C_interface
## Description
This project is to demonstrate a 1D Stencil of Vector X, then place the result into Vector Y. The purpose is to compare the difference in time of creating the same project through Assembly with a C interface, versus one that was made purely with C.

## Correctness Test
Before the comparative time analysis, we did a correctness test to show that both return correct outputs. This was first tested with the sample input and output given in the machine project specs. 
![image](https://github.com/GeckoJnlx3/LBYARCH_Agero-Sales_x86-to-C_interface/assets/103810781/7cded45a-69f8-4b93-a31a-5d768c32b14c)
![image](https://github.com/GeckoJnlx3/LBYARCH_Agero-Sales_x86-to-C_interface/assets/103810781/0eefbf65-edf2-490b-a287-0c003c90da0f)
Both result to the same expected output, passing the first test.

Next, we will run the program with a length of 2^5. For the correctness of the output, we will be using the program made purely with C as the basis.
![image](https://github.com/GeckoJnlx3/LBYARCH_Agero-Sales_x86-to-C_interface/assets/103810781/193dd6b2-db21-4300-9e07-14c538284447)

Since ASM + C shares the same output as Pure C, we can say that both programs are correct and are ready for comparative time analysis.

## Comparative Time Analysis
The comparative time analysis was run on a computer with the following specs: 
- CPU: AMD Ryzen 7 3700X
- RAM; 32GB
- GPU: Nvidia GeForce RTX 3060 Ti

We then proceeded to run the test on C and ASM + C, both on Debug and Release mode on Visual Studio 2022. Each version was run 30 times and their specific times can be found [here](https://docs.google.com/spreadsheets/d/1ZAmcgKvASDndtUG3vLrm9TzxIHdt-4p7xKA2H_4wb4c/edit?usp=sharing). 

### Average time taken in seconds 

| - | ASM + C	(Debug) | C	(Debug) | ASM + C	(Release) | C (Release) |
| --- | :---: | :---: | :---: | :---: |
| 2<sup>20</sup>	| 0.0068667	| 0.0121667	| 0.0048333	| 0.0027333   |
| 2<sup>24</sup>	| 0.1021333	| 0.1928333	| 0.0738	| 0.0452333   |
| 2<sup>30</sup>	| 6.2839333	| 12.3101667 |	4.6863333 |	2.7234667 |

The table above shows the average time taken in seconds when running each program in Debug and in Release mode. To understand the results better, we got the difference in speed from using Debug or Release mode.

### Speed Increase/Decrease of Debug to Release				
| - | ASM + C | % | C | % |
| --- | :---: | :---: | :---: | :---: |
| 2<sup>20</sup>	| -0.0020334	| -29.61%	| -0.0094334	| -77.53%
| 2<sup>24</sup>	| -0.0283333	| -27.74%	| -0.1476	| -76.54% 
| 2<sup>30</sup> | -1.5976	| -25.42%	| -9.5867	| -77.88%

In this table, we find that regardless of language, running release mode speeds up the process, especdially for C, decreasing the time by about 77% of debug time. This is because debug mode creates an additional file that allows programmers to better see and analyze the possible issues in their code. The release mode instead, generates a version of the code that is more optimized. The purpose of the build mode is to create something more for general use.
				
###  Speed Increase/Decrease of C to ASM + C				
| - | Debug	| % |	Release	| % |
| --- | :---: | :---: | :---: | :---: |
| 2<sup>20</sup>	| -0.0053	| -43.56%	| 0.0021	| 76.83%
| 2<sup>24</sup>	| -0.0907	| -47.04%	| 0.0285667	| 63.15%
| 2<sup>30</sup>	| -6.0262334	| -48.95%	| 1.9628666	| 72.07%

In this table, we find that ASM + C runs faster than purely C during debug mode, but runs much slower in release mode.
