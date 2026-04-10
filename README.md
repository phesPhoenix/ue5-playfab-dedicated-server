# ue5-playfab-dedicated-server
A dedicated server integration for Unreal Engine 5 using the Azure PlayFab GSDK. This sets up a custom GameInstance that hooks into the Azure cloud, enabling the server to run on PlayFab's multiplayer infrastructure.
What it does

Registers GSDK lifecycle delegates on server startup: shutdown, health check, server active, and ready-for-players
Signals PlayFab that the server is ready to receive players via UGSDKUtils::ReadyForPlayers()
Sets the default server host port in server builds via UGSDKUtils::SetDefaultServerHostPort()
Handles  shutdown via FPlatformMisc::RequestExit

Stack

Unreal Engine 5
Azure PlayFab Multiplayer Servers
PlayFab GSDK (Unreal plugin)
Tested locally using the PlayFab LocalMultiplayerAgent
