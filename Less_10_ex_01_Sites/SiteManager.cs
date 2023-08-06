using System;
using WebSites; //!1b -//!1e
//!7b
//    User Interface for managing Web Sites.
class SiteManager
{
	// Collection of WebSites.
	SiteList sites = new SiteList();

	// Program Entry Point - MUST be static
	      //!!!!!!!!
	public static void Main() // static !!!!!!!
	{
		SiteManager mgr = new SiteManager();

		mgr.sites = new SiteList();
		mgr.sites[mgr.sites.NextIndex] = new WebSite(
			"Joe",
			"http://www.mysite.com", 
			"Great Site.");
		mgr.sites[mgr.sites.NextIndex] = new WebSite(
			"Don", 
			"http://www.dondotnet.com", 
			"Must See.");
		mgr.sites[mgr.sites.NextIndex] = new WebSite(
			"Bob", 
			"www.bob.com", 
			"No http://");
 
		mgr.ShowMenu();
	}
 
	public void ShowMenu()
	{
		string choice;
 
		do
		{
			Console.WriteLine("Web Site Editor\n");
 
			Console.WriteLine("A - Add");
			Console.WriteLine("D - Delete");
			Console.WriteLine("M - Modify");
			Console.WriteLine("R - Report");
			Console.WriteLine("Q - Quit");
 
			Console.Write("\nPlease Choose:  ");
 
			choice = Console.ReadLine();
 
			switch (choice.ToUpper()) 
			{
				case "A":
					AddSite();
					break;
				case "D":
					DeleteSite();
					break;
				case "M":
					ModifySite();
					break;
				case "R":
					ViewSites();
					break;
				case "Q":
					choice = "Q";
					break;
				default:
					Console.WriteLine(
						"({0})? Err...That's not what I expected.", choice);
					break;
			}
		} while (choice != "Q");
	}
    static int count=0;

	private void AddSite()
	{
		string siteName;
		string url;
		string description;

		Console.Write("Please Enter Site Name: ");
		siteName = Console.ReadLine();

		Console.Write("Please Enter URL: ");
		url = Console.ReadLine();

		Console.Write("Please Enter Description: ");
		description = Console.ReadLine();

		sites[sites.NextIndex] = new WebSite(siteName,
			url,
			description);
		count++;
	}
	private void DeleteSite()
	{
		string choice;

		do 
		{
			Console.WriteLine("\nDeletion Menu\n");

			DisplayShortList();

			Console.Write(
				"\nPlease select an item to delete: ");

			choice = Console.ReadLine();

			if (choice == "Q" || choice == "q")
				break;

			int ind = Convert.ToInt32(choice);

			if (ind >= 0 && ind <= sites.NextIndex)
			{
				sites.Remove(Convert.ToInt32(choice) - 1);
				count--;
			}
		} while (true);
	}

	// No Implementation Yet.
	private void ModifySite()
	{
		Console.WriteLine("Modifying Sites.");
	}

	private void ViewSites()
	{
		Console.WriteLine("");
		for (int i=0; i < sites.NextIndex; i++)
		{
			Console.WriteLine("Site: {0}", 
				sites[i].ToString());
		}
		Console.WriteLine("");
	}

	private void DisplayShortList()
	{
		for (int i=0; i < sites.NextIndex; i++)
		{
			Console.WriteLine("{0} - {1}", 
				i+1, 
				sites[i].ToString());
		}
		Console.WriteLine("Q - Quit (Back To Main Menu)");
	}
}
//!7e
