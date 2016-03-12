To run tests, you need to do following steps:
1. Disable signing for P23.MetaTrader4.Manager.Contracts: Project Properties->Signing->Remove checkbox: "Sign the assembly"
2. Disable signing for P23.MetaTrader4.Manager.ClrWrapper: Project Properties->Properties->Configuration Properties->Linker->Advanced->Key File: delete value
3. Create text file "credentials.config" in P23.MetaTrader4.Manager.Tests folder
4. Specify credentials in "credentials.config" in format: "LOGIN,PASSWORD,SERVERIP:PORT"