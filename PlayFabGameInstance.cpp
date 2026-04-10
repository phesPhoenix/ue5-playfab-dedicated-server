#include "PlayFabGameInstance.h"
#include "PlayfabGSDK.h"
#include "GSDKUtils.h"

DEFINE_LOG_CATEGORY(LogPlayFabGSDKGameInstance);

void UPlayFabGameInstance::Init()
{

	FOnGSDKShutdown_Dyn OnGSDKShutdown;
	OnGSDKShutdown.BindDynamic(this, &UPlayFabGameInstance::OnGSDKShutdown);

	FOnGSDKHealthCheck_Dyn OnGSDKHealthCheck;
	OnGSDKHealthCheck.BindDynamic(this, &UPlayFabGameInstance::OnGSDKHealthCheck);

	FOnGSDKServerActive_Dyn OnGSDKServerActive;
	OnGSDKServerActive.BindDynamic(this, &UPlayFabGameInstance::OnGSDKServerActive);

	FOnGSDKReadyForPlayers_Dyn OnGSDKReadyForPlayers;
	OnGSDKReadyForPlayers.BindDynamic(this, &UPlayFabGameInstance::OnGSDKReadyForPlayers);

	UGSDKUtils::RegisterGSDKShutdownDelegate(OnGSDKShutdown);
	UGSDKUtils::RegisterGSDKHealthCheckDelegate(OnGSDKHealthCheck);
	UGSDKUtils::RegisterGSDKServerActiveDelegate(OnGSDKServerActive);
	UGSDKUtils::RegisterGSDKReadyForPlayers(OnGSDKReadyForPlayers);

#if UE_SERVER
	UGSDKUtils::SetDefaultServerHostPort();
#endif
}

void UPlayFabGameInstance::OnStart()
{
	UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Reached onStart!"));
	UGSDKUtils::ReadyForPlayers();
}

void UPlayFabGameInstance::OnGSDKShutdown()
{
	UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Shutdown!"));
	FPlatformMisc::RequestExit(false);
}

bool UPlayFabGameInstance::OnGSDKHealthCheck()
{
	return true;
}

void UPlayFabGameInstance::OnGSDKServerActive()
{
	UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Active!"));
}

void UPlayFabGameInstance::OnGSDKReadyForPlayers()
{
	UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Ready for players!"));
}