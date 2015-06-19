using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class BackupInfo
    {
        public string File { get; set; }              // file name
        public int Size { get; set; }                 // file size
        public UInt32 Time { get; set; }              // file time
    }
}
