using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class UserRecord
    {
        //--- common settings
        public int Login { get; set; }                     // login
        public string Group { get; set; }                  // group
        public string Password { get; set; }               // password
        //--- access flags
        public int Enable { get; set; }                    // enable
        public int EnableChangePassword { get; set; }      // allow to change password
        public int EnableReadOnly { get; set; }            // allow to open/positions (TRUE-may not trade)
        //---
        public string PasswordInvestor { get; set; }       // read-only mode password
        public string PasswordPhone { get; set; }          // phone password
        public string Name { get; set; }                   // name
        public string Country { get; set; }                // country
        public string City { get; set; }                   // city
        public string State { get; set; }                  // state
        public string ZipCode { get; set; }                // zipcode
        public string Address { get; set; }                // address
        public string Phone { get; set; }                  // phone
        public string Email { get; set; }                  // email
        public string Comment { get; set; }                // comment
        public string Id { get; set; }                     // SSN (IRD)
        public string Status { get; set; }                 // status
        public UInt32 Regdate { get; set; }                // registration date
        public UInt32 LastDate { get; set; }               // last coonection time
        //--- trade settings
        public int Leverage { get; set; }                  // leverage
        public int AgentAccount { get; set; }              // agent account
        public UInt32 Timestamp { get; set; }              // timestamp
        public int LastIp { get; set; }                    // last visit ip
        //---            торговые данные
        public double Balance { get; set; }                // balance
        public double PrevMonthBalance { get; set; }       // previous month balance
        public double PrevBalance { get; set; }            // previous day balance
        public double Credit { get; set; }                 // credit
        public double InterestRate { get; set; }           // accumulated interest rate
        public double Taxes { get; set; }                  // taxes
        public double PrevMonthEquity { get; set; }        // previous month equity
        public double PrevEquity { get; set; }             // previous day equity
        //---
        public string PublicKey { get; set; }              // public key
        public int SendReports { get; set; }               // enable send reports by email
        public UInt32 Mqid { get; set; }                   // MQ client identificator
        public UInt32 UserColor { get; set; }              // color got to client (used by MT Manager)
    }
}
