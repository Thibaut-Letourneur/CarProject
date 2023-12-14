.PHONY: test_track

test_track: $(BIN_DIR)/test_track

$(BIN_DIR)/test_track: $(OBJ_DIR)/tests/test_track.o $(OBJ_DIR)/track/track.o $(OBJ_DIR)/utils/utils.o
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/tests/test_track.o: $(TEST_DIR)/track/test_track.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ 