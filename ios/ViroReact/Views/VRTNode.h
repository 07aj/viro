//
//  VRTNode.h
//  React
//
//  Created by Raj Advani on 8/24/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VRTView.h"
#import "RCTComponent.h"
#import "RCTBridge.h"

extern const int k2DPointsPerSpatialUnit;

@interface VRTNode : VRTView

- (instancetype)initWithBridge:(RCTBridge *)bridge;

@property (readonly, nonatomic) std::shared_ptr<VRONode> node;

// Rendering properties
@property (nonatomic, copy, nullable) NSArray<NSString *> *materials;
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *position;
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *rotation;
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *scale;
@property (nonatomic, assign) float opacity;
@property (nonatomic, copy, nullable) NSArray<NSString *> *transformBehaviors;
@property (nonatomic, assign) BOOL visible;

// Event properties
@property (nonatomic, copy, nullable) RCTDirectEventBlock onTap;
@property (nonatomic, copy, nullable) RCTDirectEventBlock onGaze;
@property (nonatomic, assign) BOOL highAccuracyGaze;

// Used for Flexbox enabled components, no-op for non flexbox related components.
@property(nonatomic) CGPoint centerPoint2D;
@property(nonatomic) CGRect bounds2D;

- (void)reactSetFrame:(CGRect)frame;
- (BOOL)isRootFlexboxView;
- (CGPoint)fudgeFlexboxScaleX:(float)width3d Y:(float)height3d;

// Apply materials stored in _materials property to current node geometry if geometry is not null.
- (void)applyMaterials;

@end
