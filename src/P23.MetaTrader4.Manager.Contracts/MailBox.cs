using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents mailbox
    /// </summary>
    public class MailBox
    {
        /// <summary>
        /// Receive time
        /// </summary>
        public UInt32 Time { get; set; }

        /// <summary>
        /// Mail sender (login)
        /// </summary>
        public int Sender { get; set; }

        /// <summary>
        /// Mail sender (name)
        /// </summary>
        public string From { get; set; }

        /// <summary>
        /// Mail recipient
        /// </summary>
        public int To { get; set; }

        /// <summary>
        /// Mail sumbect
        /// </summary>
        public string Subject { get; set; }

        /// <summary>
        /// Readed flag
        /// </summary>
        public int Readed { get; set; }

        /// <summary>
        /// Pointer to mail Body
        /// </summary>
        public string Body { get; set; }

        /// <summary>
        /// Mail Body length
        /// </summary>
        public int BodyLen { get; set; }

        /// <summary>
        /// Minimum build
        /// </summary>
        public short BuildMin { get; set; }

        /// <summary>
        /// Maximum build
        /// </summary>
        public short BuildMax { get; set; }
    }
}
