// Fill out your copyright notice in the Description page of Project Settings.

#include "Noah.h"
#include "NoahCharacter.h"


// Sets default values
ANoahCharacter::ANoahCharacter() : m_zoomMax(500), m_zoomMin(200)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

												// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	Inventory = CreateDefaultSubobject<UInventory>(TEXT("Inventory"));
	Craft = CreateDefaultSubobject<UCraft>(TEXT("Craft"));
}

// Called when the game starts or when spawned
void ANoahCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogClass, Log, TEXT("Noah:ANoahCharacter BeginPlay"));
}

// Called every frame
void ANoahCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANoahCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ANoahCharacter::Attack);

	PlayerInputComponent->BindAxis("MoveForward", this, &ANoahCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANoahCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ANoahCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ANoahCharacter::LookUpAtRate);
	PlayerInputComponent->BindAxis("CameraZoom", this, &ANoahCharacter::CameraZoomRate);
}

void ANoahCharacter::Attack()
{
	//PlayAnimMontage();
}

void ANoahCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ANoahCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ANoahCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ANoahCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}


void ANoahCharacter::CameraZoomRate(float Rate)
{
	CameraBoom->TargetArmLength += Rate;

	if (CameraBoom->TargetArmLength >= m_zoomMax) {
		CameraBoom->TargetArmLength = m_zoomMax;
	}
	else if (CameraBoom->TargetArmLength <= m_zoomMin) {
		CameraBoom->TargetArmLength = m_zoomMin;
	}
}
bool ANoahCharacter::DetectObject(AActor* detectedObject)
{
	UE_LOG(LogClass, Log, TEXT("asdffdssfdasadfsdfa %d"), DetectedObject.Num());

	for (int i = 0; i < DetectedObject.Num(); i++) {
		if (DetectedObject[i] == detectedObject) return false;
	}

	DetectedObject.Add(detectedObject);

	return true;
}

bool ANoahCharacter::MissObject(AActor* missedObject)
{
	for (int i = 0; i < DetectedObject.Num(); i++) {
		if (DetectedObject[i] == missedObject) {
			DetectedObject.RemoveSingle(missedObject);
			return true;
		}
	}

	return false;
}

AActor* ANoahCharacter::FindNearItem()
{
	//예외처리
	if (DetectedObject.Num() <= 0) return nullptr;

	AActor* near = DetectedObject[0]; //가장 가까운 Actor
	FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(); //캐릭터 위치

	for (int i = 0; i < DetectedObject.Num(); i++) {
		if (FVector::Dist(DetectedObject[i]->GetActorLocation(), playerLocation) < FVector::Dist(near->GetActorLocation(), playerLocation)) {
			near = DetectedObject[i];
		}
	}

	return near;
}