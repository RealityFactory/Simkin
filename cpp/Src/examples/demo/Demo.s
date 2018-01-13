{
	[ Edit this file and then press "Reload" on the dialog to see the results 
	
	  The functions you can call are:

	  run(command)	-	runs another program
	  user(text)	-	shows a message box

	  reload		-	reloads the dialog
	  close			-	closes the dialog

	  setFocus(id)	-	sets focus to the control with the given id
	  getText(id)	-	retrieves the text from a control

	  You can also define your own methods inside this file that you can call
	]

	View
	{
		Title [Simkin Demo]
		X [120]
		Y [100]
		Width [250]
		Height [190]
		Controls
		{
			{
				Type [Static]
				Text [This window and its behaviour are defined in Demo.s]
				X [10]
				Y [10]
				Width [240]
				Height [40]
			}
			{
				Type [Static]
				Text [Prompt:]
				X [10]
				Y [60]
				Width [60]
				Height [20]
			}
			{
				Type [Edit]
				X [80]
				Y [60]
				Width [100]
				Height [20]
				Id [1]
			}
			{
				Type [Button]
				Text [OK]
				Id [2]
				X [10]
				Y [100]
				Width [60]
				Height [20]
				Method [okPressed]
			}
			{
				Type [Button]
				Text [Cancel]
				Id [3]
				X [80]
				Y [100]
				Width [60]
				Height [20]
				Method [cancelPressed]
			}
			{
				Type [Button]
				Text [Reload]
				Id [4]
				X [10]
				Y [130]
				Width [60]
				Height [20]
				Method [reload]
			}
			{
				Type [Button]
				Text [Edit Demo.s]
				Id [5]
				X [80]
				Y [130]
				Width [90]
				Height [20]
				Method [edit]
			}
		}
	}
	init [ () 
	{ 
		setFocus(1); 
	}]
	okPressed [ () 
	{ 
		user("You typed " # getText(1)); close(); 
	}]
	cancelPressed [ () 
	{ 
		user("You cancelled the dialog!"); close(); 
	}]
	edit [ () 
	{ 
		run("notepad demo.s"); 
	}]
}