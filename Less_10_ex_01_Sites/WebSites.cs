namespace WebSites //!1b -//!1e
{
	using System;
	using System.Collections;
	public class WebSite 
	{
        //!2b
        //!!!
		//can only be initialized at the declaration of the field
		const string http      = "http://";
		       //!!!
		              //!!! F1
		              //can be initialized only
		              //    either at the declaration 
		              //    or in a constructor
		                                            //!!!.........!!!!!!!
		public static readonly string currentDate = new DateTime().ToString();
		//!2e

		string siteName;
		string url;
		string description;
	
		// Constructors
	
		// Default Constructor
		// Invokes another constructor with 3 default parameters
		public WebSite() 
			: this("No Site", "no.url", "No Description") {}
		public WebSite(string newSite) 
			: this(newSite, "no.url", "No Description") {}
		public WebSite(string newSite, string newURL) 
			  //!!
			: this(newSite, newURL, "No Description") {}
		public WebSite(string newSite, string newURL, string newDesc) 
		{
			SiteName    = newSite;
			URL         = newURL;
			Description = newDesc;
		}
	
		//!3b Object functions
		       //!!! F1
		public override string ToString() 
		{
			return siteName + ", " + url + ", " + description;
		}	
		       //!!        
		public override bool Equals(object evalString) 
		{
			return this.ToString() == evalString.ToString();
		}
		//!!!!!
		protected string ValidateUrl(string url) 
		{
			          //!!!
			if (!(url.StartsWith(http))) 
			{
				return http + url;
			}
			
			return url;
		}
		//!3e	
		
		//!4b Properties
		// property!!!
		public string SiteName 
		{
			get 
			{
				return siteName;
			}
			set 
			{
				siteName = value;
			}
		}
		// property!!!
		public string URL 
		{
			get 
			{
				return url;
			}
			set 
			{
				url = ValidateUrl(value);
			}
		}
		public string Description 
		{
			get 
			{
				return description;
			}
			set 
			{
				description = value;
			}
		}
	    //!4e

		// Destructor
		~WebSite() {}
	   
	}

 

	public class SiteList 
	{
		//!5b see System.Collections
		//        //!! Collection 
		protected SortedList sites;
		//!5e

		// Constructor
		public SiteList() 
		{
			       //here is the good place to construct it
			sites = new SortedList();
		}
	
		// Properties
		public int NextIndex 
		{
			get 
			{
				return sites.Count;
			}
			//!!!
			// !! there is no set !!
		}
	
		//!6b Indexer
		// Adds and retrieves Web Site at index.
		public WebSite this[int index] 
		{
			get 
			{
				if (index >= sites.Count)
					return (WebSite)null;
				                       //SortedList internal method
				return (WebSite) sites.GetByIndex(index);
			}
			set 
			{
				if ( index <= sites.Count )
					sites[index] = value; //!!!		
			}
		}
		//!6e

		// Methods
		public void Remove(int element) 
		{
            for (int i = element; i < sites.Count - 1; i++)
                sites[i] = sites[i + 1];
            sites.RemoveAt(sites.Count - 1);
            // try instead of the 3 lines
            //sites.RemoveAt(element);
        }
	}
}
