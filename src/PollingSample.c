/* Copyright (C) 2012-2017 Ultraleap Limited. All rights reserved.
 *
 * Use of this code is subject to the terms of the Ultraleap SDK agreement
 * available at https://central.leapmotion.com/agreements/SdkAgreement unless
 * Ultraleap has signed a separate license agreement with you or your
 * organisation.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "LeapC.h"
#include "ExampleConnection.h"

int64_t lastFrameID = 0; //The last frame received

int main(int argc, char** argv) {
  OpenConnection();
  while(!IsConnected)
    millisleep(100); //wait a bit to let the connection complete

  printf("Connected.");
  LEAP_DEVICE_INFO* deviceProps = GetDeviceProperties();
  if(deviceProps)
    printf("Using device %s.\n", deviceProps->serial);

  for(;;){
    LEAP_TRACKING_EVENT *frame = GetFrame();
    if(frame && (frame->tracking_frame_id > lastFrameID)){
      lastFrameID = frame->tracking_frame_id;
      printf("Frame %lli with %i hands.\n", (long long int)frame->tracking_frame_id, frame->nHands);
      for(uint32_t h = 0; h < frame->nHands; h++){
        LEAP_HAND* hand = &frame->pHands[h];
        printf("    Hand id %i is a %s hand with position (%f, %f, %f).\n",
                    hand->id,
                    (hand->type == eLeapHandType_Left ? "left" : "right"),
                    hand->palm.position.x,
                    hand->palm.position.y,
                    hand->palm.position.z);
        printf("        Thumb:\n");
        printf("            id: %i\n", hand->thumb.finger_id);
        for (uint32_t b = 0; b < 4; b++) {
          printf("            bone[%i]: base(%f, %f, %f) -> end(%f, %f, %f)\n",
            b,
            hand->thumb.bones[b].prev_joint.x,
            hand->thumb.bones[b].prev_joint.y,
            hand->thumb.bones[b].prev_joint.z,
            hand->thumb.bones[b].next_joint.x,
            hand->thumb.bones[b].next_joint.y,
            hand->thumb.bones[b].next_joint.z
          );
        }
        printf("        Index:\n");
        printf("            id: %i\n", hand->index.finger_id);
        for (uint32_t b = 0; b < 4; b++) {
          printf("            bone[%i]: base(%f, %f, %f) -> end(%f, %f, %f)\n",
            b,
            hand->index.bones[b].prev_joint.x,
            hand->index.bones[b].prev_joint.y,
            hand->index.bones[b].prev_joint.z,
            hand->index.bones[b].next_joint.x,
            hand->index.bones[b].next_joint.y,
            hand->index.bones[b].next_joint.z
          );
        }
        printf("        Middle:\n");
        printf("            id: %i\n", hand->middle.finger_id);
        for (uint32_t b = 0; b < 4; b++) {
          printf("            bone[%i]: base(%f, %f, %f) -> end(%f, %f, %f)\n",
            b,
            hand->middle.bones[b].prev_joint.x,
            hand->middle.bones[b].prev_joint.y,
            hand->middle.bones[b].prev_joint.z,
            hand->middle.bones[b].next_joint.x,
            hand->middle.bones[b].next_joint.y,
            hand->middle.bones[b].next_joint.z
          );
        }
        printf("        Ring:\n");
        printf("            id: %i\n", hand->ring.finger_id);
        for (uint32_t b = 0; b < 4; b++) {
          printf("            bone[%i]: base(%f, %f, %f) -> end(%f, %f, %f)\n",
            b,
            hand->ring.bones[b].prev_joint.x,
            hand->ring.bones[b].prev_joint.y,
            hand->ring.bones[b].prev_joint.z,
            hand->ring.bones[b].next_joint.x,
            hand->ring.bones[b].next_joint.y,
            hand->ring.bones[b].next_joint.z
          );
        }
        printf("        Pinky:\n");
        printf("            id: %i\n", hand->pinky.finger_id);
        for (uint32_t b = 0; b < 4; b++) {
          printf("            bone[%i]: base(%f, %f, %f) -> end(%f, %f, %f)\n",
            b,
            hand->pinky.bones[b].prev_joint.x,
            hand->pinky.bones[b].prev_joint.y,
            hand->pinky.bones[b].prev_joint.z,
            hand->pinky.bones[b].next_joint.x,
            hand->pinky.bones[b].next_joint.y,
            hand->pinky.bones[b].next_joint.z
          );
        }
      }
    }
  } //ctrl-c to exit
  return 0;
}
//End-of-Sample
