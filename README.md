MetaTrader4.Manager.Wrapper
===========================

.NET Wrapper around native mtmanager.dll, for MetaTrader 4 manager API.

##Installation

To use these providers you will need to install the `MetaTrader4.Manager.Wrapper` NuGet package:

```
Install-Package MetaTrader4.Manager.Wrapper
```

##Using wrapper in Request mode

Data can be accessed using `*Request` methods.

```
	using (var metatrader = new ClrWrapper(new ConnectionParameters
			{
				Login = 123456,
				Password = "managerPassword",
				Server = "123.123.123.123:443"
			}))
	{
		IList<UserRecord> users = metatrader.UsersRequest();
	}
```

##Using wrapper in Pumping mode

Pumping mode allows to get notifications about changes regarding users, trades and etc. Data can be accessed using `*Get` methods.

```
	var are = new AutoResetEvent(false);
	using (var metatrader = new ClrWrapper(new ConnectionParameters
			{
				Login = 123456,
				Password = "managerPassword",
				Server = "123.123.123.123:443"
			}))
	{
		metatrader.PumpingSwitch(i =>
		{
			if (i == 0) // 0 - means pumping started
				are.Set();
		});

		are.WaitOne();
		
		IList<UserRecord> users = metatrader.UsersGet();
	}
```

##Using wrapper in Extended Pumping mode

In Extended Pumping mode notification comes together with new data, so there is no need to call `*Get` method.

```
	var are = new AutoResetEvent(false);
	using (var metatrader = new ClrWrapper(new ConnectionParameters
			{
				Login = 123456,
				Password = "managerPassword",
				Server = "123.123.123.123:443"
			}))
	{
		metatrader.PumpingSwitchEx();
		metatrader.TradeAdded += (sender, record) =>
		{
			Console.WriteLine(record);
		};
		metatrader.PumpingStarted += (sender, eventArgs) =>
		{
			are.Set();
		};
		are.WaitOne();
	}
```