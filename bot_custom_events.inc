Sub Event_Timer(Timer,OriginalValue)
    /if (${String[${Timer}].Equal[InnyDoomTimer]}) /call InnyDoomTimer ${OriginalValue}
/return

Sub SetupCustomEvents
    | hateplaneb
    /if (${Zone.ID}==76) /declare InnyDoomTimer timer global 5s
/return

#event UpdateFollowDistance "<#1#> follow at #2#"
Sub Event_UpdateFollowDistance(Line, r, v)
  /varset followDistance ${v}
  /if (${Me.Class.ID} == 2) {
    /varset FollowMethod stick|${v} healer
  
  } else {
    /varset FollowMethod stick|${v} healer
  
  }
  /echo ${FollowMethod}
/return

|### hateplaneb Inny Doom

#event Summon "<#1#> summon"
Sub Event_Summon(Line, t)
  /bc woah
  /if ( ${Me.Class.ID} == 13 ) {
    /bc summoning ${t}
    /target ${t}
	/keypress =
	:SummonLoop
	/if (${Me.Casting}) /goto :SummonLoop
  }
/return

#event CallSummon "<#*#> callsummon #1# "
Sub Event_CallSummon(Line, callwho)
   /if ( ${Me.Class.ID} == 13 ) {
    /bc summoning ${callwho}
    /target ${callwho}
	/keypress =
	:SummonLoop
	/if (${Me.Casting}) /goto :SummonLoop
  }
/return

#event InnyDoom "#*#You feel a sense of doom upon you.#*#"

Sub Event_InnyDoom
    /if (${AnnounceChannel.NotEqual[NULL]}) /docommand /${AnnounceChannel} Inny wants to DT me!
    /while ( ${Me.Song[Doom].ID} && ${Me.State.NotEqual[HOVER]} ) {
        /bc -- Need Cure for Doom --
        /delay 2s ${Spawn[Cleansing Aura].ID}
        /doevents
        /moveto id ${Spawn[Cleansing Aura].ID} loose
	    /delay 2s ${Math.Distance[${Me.Y},${Me.X}:${YLOC},${XLOC}]}<10
	}
/return

Sub InnyDoomTimer(OriginalValue)
    /if (${Zone.ID}==76) {
        /call InnyDoomAura
    }
    /varset InnyDoomTimer ${OriginalValue}
/return

Sub InnyDoomAura
    | Calls the Aura location for the raid, fixed approximate X locations are:
    |   X=104 == door
    |   X=125 == Corner
    |   X=-4 == Spawn
    
	/if (${Zone.ID}==76 && ${Spawn[Cleansing Aura].ID}) {
		/declare X int local
		/varset X ${Spawn[Cleansing Aura].X}
		/if (${X} < 0) {
			/rsay Aura at SPAWN
		} else /if ( ${X} < 112 ) {
			/rsay Aura at DOOR
		} else {
			/rsay Aura at CORNER
		}
	} else {
        /bc Can't find cleansing aura!
    }
/return

#event Develop "<#1#> develop"
Sub Event_Develop
/return

Sub DoINuke
  
	/if (${Me.XTarget} > 0 ) {
	  /declare x int local
	  /for x 1 to ${Me.XTarget}
        /if (${Spawn[${Me.XTarget[${x}]}].CurrentHPs} < 80) {
		  /varset doNuke TRUE
		} else {
		  /varset doNuke FALSE
		}
      /next x
	} else {
	  /varset doNuke FALSE
	}
/return ${doNuke}

#event DOT "<#1#> DOT #2#"
Sub Event_DOT(Line, who, t)
  /if (${Me.Class.ID}==2) {
    /target ${t}
	/casting "Sermon of Sanction|gem6"
    /bc Sermon of Sanction -> ${t}
  }
/return

#event HAMMER "<#1#> HAMMER #2#"
Sub Event_HAMMER(Line, who, t)
  /if (${Me.Class.ID}==2) {
    /target ${t}
	/casting "Celestial Hammer|alt"
    /bc Celestial Hammer -> ${t}
  }
/return

#event TURN "<#1#> TURN #2#"
Sub Event_TURN(Line, who, t)
  /if (${Me.Class.ID}==2) {
    /target ${t}
	/casting "Turn Undead"
    /bc TurnUndead -> ${t}
  }
/return

#event TellsYou "#1# tells you, #2#"
Sub Event_TellsYou(Line, person, msg}
  /if ( ${Me.Class.ID} == 2 ) /tell Phrogeater ${person} says someting
/return

#event Med "<#*#> med"
Sub Event_Med
  /bc starting to meditate
  :ManaLoop
  /if ( ${Me.PctMana} < 75 && ${Me.Class.ID} == 13 ) /goto :ManaLoop
  /bc finished medding
/return

#event Exp "<#1#> exp"
Sub Event_Exp(Line, requestor)
  /bc ${Me.Exp}
/return`

#event Swarm "<#1#> swarm #2#"
Sub Event_Swarm(Line, requestor, t)
  /if (${Me.Class.ID} == 13) {
    /if ( ${Me.AltAbilityReady[Host of the Elements]} ) {
	  /target ${t}
	  /bc Host of the Elements -> ${t}
	  /casting "Host of the Elements|alt"
	} else {
	  /bc "Host of the Elements is not ready yet!!"
	  /target ${t}
	  /pet swarm
	}
  }
/return



#event Pacify "<#1#> pacify #2#"
Sub Event_Pacify(Line, player, targ)

  /target ${targ}
  /delay 3
  /casting "Placating Glow"
  /delay 5s
/return

#event Speak "<#*#> questsay #1# :: #2#"
Sub Event_Speak(Line, who, m)
  /declare name string local ${Spawn[${who}].CleanName}
  /target ${who}
  /delay 3
  /say ${m}
/return

#event Build "<#*#> build"
Sub Event_Build()
  /if (${Me.Class.ID}==13) {
    /if (!${Me.Buff[Improved Twincast].ID}) {
	  /if ( ${Me.AltAbilityReady[Improved Twincast]} ) {
	  
	    /casting "Improved Twincast|alt"
	  } else {
	    /bc twincast is not ready ${Me.AltAbilityTimer[Improved Twincast]}
	  }
	}
  }
/return