using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class SymbolCommandsTests
    {
        [TestMethod]
        public void GetSymbolInfo()
        {
            using (var mt = new ClrWrapper(new ConnectionParameters { Login = 0, Password = "", Server = "" }, @"D:\ProgrammingWorkspace\MetaTrader4.Manager.Wrapper\src\Libraries\mtmanapi\mtmanapi.dll"))
            {
                mt.SymbolsRefresh();
                //without pumping, but depends on MT server settings
                var r = mt.TicksRequest(new TickRequest() {Symbol = "EURUSD", From = 0, To = int.MaxValue, Flags = (char) 3});
                Assert.IsNotNull(r);
                
                var p = mt.PumpingSwitch((delegate(int i)
                {
                    //wait until 0 recieved, thats mean pumping started, and after 
                    //you will be able to recieve new quotes and access them
                }));
                Assert.AreEqual(0, p);
                mt.SymbolAdd("EURUSD");
                Thread.Sleep(30000);
                var symbol = mt.SymbolInfoGet("EURUSD");
                Assert.IsNotNull(symbol);
            }
        }
    }
}