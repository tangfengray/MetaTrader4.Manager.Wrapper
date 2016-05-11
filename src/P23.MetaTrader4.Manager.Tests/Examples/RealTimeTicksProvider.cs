using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests.Examples
{
    [TestClass]
    public class RealTimeTicksProvider
    {
        [TestMethod]
        public void Run()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var autoResetEvent = new AutoResetEvent(false);
                var symbols = mt.CfgRequestSymbol();
                mt.SymbolsRefresh();
                foreach (var symbol in symbols)
                {
                    mt.SymbolAdd(symbol.Name);
                }
                mt.PumpingSwitchEx();
                
                mt.BidAskUpdated += (sender, args) =>
                {
                    var total = 0;
                    do
                    {
                        var symbolsInfos = mt.SymbolInfoUpdated();
                        foreach (var symbolInfo in symbolsInfos)
                        {
                            Console.WriteLine("{0} {1} {2}", DateTime.Now, symbolInfo.Symbol, symbolInfo.Bid);
                            if (symbolInfo.Symbol == "EURUSD")
                            {
                                autoResetEvent.Set();
                            }
                        }
                        total = symbolsInfos.Count;
                    } while (total > 0);
                };

                autoResetEvent.WaitOne(new TimeSpan(0, 1, 0));
            }
        }
    }
}
