using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents user record
    /// </summary>
    public class UserRecord
    {
        /// <summary>
        /// Account number
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// Group user belongs to
        /// </summary>
        public string Group { get; set; }

        /// <summary>
        /// User password
        /// </summary>
        public string Password { get; set; }

        /// <summary>
        /// Enable
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Allow to change password
        /// </summary>
        public int EnableChangePassword { get; set; }

        /// <summary>
        /// Allow to open/positions (1 - may not trade)
        /// </summary>
        public int EnableReadOnly { get; set; }

        /// <summary>
        /// Read-only mode password
        /// </summary>
        public string PasswordInvestor { get; set; }

        /// <summary>
        /// Phone password
        /// </summary>
        public string PasswordPhone { get; set; }

        /// <summary>
        /// Name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Country
        /// </summary>
        public string Country { get; set; }

        /// <summary>
        /// City
        /// </summary>
        public string City { get; set; }

        /// <summary>
        /// State
        /// </summary>
        public string State { get; set; }

        /// <summary>
        /// ZipCode, PostCode
        /// </summary>
        public string ZipCode { get; set; }

        /// <summary>
        /// Address
        /// </summary>
        public string Address { get; set; }

        /// <summary>
        /// Phone
        /// </summary>
        public string Phone { get; set; }

        /// <summary>
        /// Email
        /// </summary>
        public string Email { get; set; }

        /// <summary>
        /// Comment
        /// </summary>
        public string Comment { get; set; }

        /// <summary>
        /// SSN (IRD)
        /// </summary>
        public string Id { get; set; }

        /// <summary>
        /// Status
        /// </summary>
        public string Status { get; set; }

        /// <summary>
        /// Registration date
        /// </summary>
        public UInt32 Regdate { get; set; }

        /// <summary>
        /// Last coonection time
        /// </summary>
        public UInt32 LastDate { get; set; }

        /// <summary>
        /// Leverage
        /// </summary>
        public int Leverage { get; set; }

        /// <summary>
        /// Agent account
        /// </summary>
        public int AgentAccount { get; set; }

        /// <summary>
        /// Timestamp wher UserRecord was requested
        /// </summary>
        public UInt32 Timestamp { get; set; }

        /// <summary>
        /// Last visit ip
        /// </summary>
        public int LastIp { get; set; }

        /// <summary>
        /// Balance
        /// </summary>
        public double Balance { get; set; }

        /// <summary>
        /// Previous month balance
        /// </summary>
        public double PrevMonthBalance { get; set; }

        /// <summary>
        /// Previous day balance
        /// </summary>
        public double PrevBalance { get; set; }

        /// <summary>
        /// Credit
        /// </summary>
        public double Credit { get; set; }

        /// <summary>
        /// Accumulated interest rate
        /// </summary>
        public double InterestRate { get; set; }

        /// <summary>
        /// Taxes
        /// </summary>
        public double Taxes { get; set; }

        /// <summary>
        /// Previous month equity
        /// </summary>
        public double PrevMonthEquity { get; set; }

        /// <summary>
        /// Previous day equity
        /// </summary>
        public double PrevEquity { get; set; }

        /// <summary>
        /// Public key
        /// </summary>
        public string PublicKey { get; set; }

        /// <summary>
        /// Enable send reports by email
        /// </summary>
        public int SendReports { get; set; }

        /// <summary>
        /// MQ client identificator
        /// </summary>
        public UInt32 Mqid { get; set; }

        /// <summary>
        /// Color got to client (used by MT Manager)
        /// </summary>
        public UInt32 UserColor { get; set; }
    }
}
