using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents backup information
    /// </summary>
    public class BackupInfo
    {
        /// <summary>
        /// File name
        /// </summary>
        public string File { get; set; }

        /// <summary>
        /// File size
        /// </summary>
        public int Size { get; set; }

        /// <summary>
        /// File time
        /// </summary>
        public UInt32 Time { get; set; }
    }
}
